#!/bin/bash

REPO="/home/ajnas/Desktop/s7CompilerLab"
LOG_DIR="$REPO/logs"

mkdir -p "$LOG_DIR"

cd "$REPO" || exit 1

log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1"
}

# --------------------
# git add .
# --------------------
ADD_LOG="$LOG_DIR/git-add.log"

log "Starting git add ." >> "$ADD_LOG"
git add . >> "$ADD_LOG" 2>&1
ADD_STATUS=$?
log "git add completed with status: $ADD_STATUS" >> "$ADD_LOG"

if [ $ADD_STATUS -ne 0 ]; then
    exit 1
fi

# --------------------
# git commit
# --------------------
COMMIT_LOG="$LOG_DIR/git-commit.log"

log "Starting git commit" >> "$COMMIT_LOG"
git commit -m "Automated commit on $(date)" >> "$COMMIT_LOG" 2>&1
COMMIT_STATUS=$?
log "git commit completed with status: $COMMIT_STATUS" >> "$COMMIT_LOG"

# No changes to commit
if [ $COMMIT_STATUS -ne 0 ]; then
    exit 0
fi

# --------------------
# git push
# --------------------
PUSH_LOG="$LOG_DIR/git-push.log"

log "Starting git push" >> "$PUSH_LOG"
git push >> "$PUSH_LOG" 2>&1
PUSH_STATUS=$?
log "git push completed with status: $PUSH_STATUS" >> "$PUSH_LOG"

exit $PUSH_STATUS
