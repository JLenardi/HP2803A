#!/usr/bin/env bash
set -euo pipefail

CODE_REPO="/home/jamesl/5_Programs/C/HP2803A"
DOC_REPO="/home/jamesl/5_Programs/C/HP2803A-docs"

echo "Publishing documentation to docs repository..."

cd "$DOC_REPO"

# Remove only generated documentation folders
rm -rf a64 avr

# Recreate structure
mkdir -p a64 avr

# Copy generated HTML
cp -r "$CODE_REPO/docs/a64/html/"* a64/
cp -r "$CODE_REPO/docs/avr/html/"* avr/

# Stage changes
git add -A

# Commit only if something changed
if git diff --cached --quiet; then
    echo "No documentation changes to publish."
else
    git commit -m "Publish Doxygen html"
    git push
    echo "Documentation published."
fi

cd "$CODE_REPO"
