.PHONY: clean build rebuild silbuild release

# Read CI prefix (used by release target to find the current version tag)
CI_PREFIX := fcs-model

# Resolve version from the exact annotated tag on HEAD (release builds only)
GIT_TAG := $(shell git describe --tags --exact-match --match "$(CI_PREFIX)-v*" 2>/dev/null)
VERSION  := $(patsubst $(CI_PREFIX)-v%,%,$(GIT_TAG))

clean:
	rm -rf build

# Incremental ARM build
build:
	@test -d build || cmake -B build \
		-DCMAKE_TOOLCHAIN_FILE=toolchain-arm.cmake \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	make -C build VERBOSE=1

# Full clean + ARM build
rebuild: clean build

# SIL build (Linux x86_64, for simulation)
silbuild: clean
	@echo "SIL build ..."
	@test -d build || cmake -B build \
		-DCMAKE_BUILD_TYPE=Debug \
		-DCMAKE_TOOLCHAIN_FILE=toolchain-linux.cmake \
		-DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	make -C build

# Release: build + generate contract sidecar
# Only valid when HEAD is exactly on a release tag
release: build
	@if [ -z "$(VERSION)" ]; then \
		echo "ERROR: HEAD is not on an exact $(CI_PREFIX)-vX.Y.Z tag."; \
		echo "       Release builds must be triggered after tagging."; \
		exit 1; \
	fi
	python3 tools/gen_model_contract.py . build/ $(VERSION)
	@echo "Release artifacts ready in build/:"
	@echo "  libcommon_lib.a"
	@echo "  libcontroller.a"
	@echo "  libvms_model.a"
	@echo "  fcs_model.contract"