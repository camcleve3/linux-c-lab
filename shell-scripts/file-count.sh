#!/usr/bin/env bash
set -Euo pipefail
trap 'echo "Error! (line $LINENO)"; exit 1' ERR

DIR="${1:-.}"
[[ -d "$DIR" ]] || { echo "Directory not found: $DIR"; exit 1; }

declare -A COUNTS=()

while IFS= read -r -d '' f; do
  name="${f##*/}"
  ext="${name##*.}"
  [[ "$name" == "$ext" ]] && ext="(no extension)"
  val=${COUNTS["$ext"]-0}
  COUNTS["$ext"]=$(( val + 1 ))
done < <(find "$DIR" -type f -print0)

ts="$(date +%F_%H-%M-%S)"
LOG="file-count_${ts}.log"

{
  echo "Directory scanned : $DIR"
  echo "Timestamp         : $(date)"
  echo "Total files       : $(find "$DIR" -type f | wc -l)"
  echo
  echo "Counts by extension:"
  for k in "${!COUNTS[@mv ]}"; do
    printf "  %-15s %d\n" "$k" "${COUNTS[$k]}"
  done | sort
} | tee "$LOG"

echo "Saved results to: $LOG"
