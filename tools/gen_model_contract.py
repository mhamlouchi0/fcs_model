#!/usr/bin/env python3
"""
gen_model_contract.py
Computes interface hashes and writes fcs_model.contract.
Called by the Makefile release target — never called by hand.

Usage:
    python3 tools/gen_model_contract.py <model_root_dir> <build_dir> <version>
"""
import hashlib, json, datetime, pathlib, sys

def file_hash(paths):
    h = hashlib.sha256()
    for p in sorted(paths):
        h.update(pathlib.Path(p).read_bytes())
    return h.hexdigest()[:16]

model_dir = pathlib.Path(sys.argv[1])
build_dir = pathlib.Path(sys.argv[2])
version   = sys.argv[3]          # e.g. "1.0.0"

include_dir = model_dir / "include"

fcs_hash = file_hash([
    include_dir / "fcs_mi_interface.h",
])

vms_hash = file_hash([
    include_dir / "vms_interface.h",
])

contract = {
    "version":        version,
    "fcs_mi_if_hash": fcs_hash,
    "vms_if_hash":    vms_hash,
    "built_at":       datetime.datetime.utcnow().isoformat() + "Z",
}

out = build_dir / "fcs_model.contract"
out.write_text(json.dumps(contract, indent=2))
print(f"Contract written to {out}")
print(f"  fcs_mi_if_hash : {fcs_hash}")
print(f"  vms_if_hash    : {vms_hash}")