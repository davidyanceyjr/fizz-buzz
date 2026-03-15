
# AGENTS.md

## Purpose

This repository is a reference implementation and working scaffold for **Phase-Oriented C** on Linux systems, emphasizing:

- human-auditable control flow
- air‑gapped operation
- low dependency footprint
- deterministic behavior
- security-conscious systems programming

Agents, contributors, and code-generation tools operating in this repository must preserve those goals.

---

# Engineering Workflow

Canonical lifecycle:

issue → branch → specification → design → implementation → tests → debug → PR → review → merge → cleanup → documentation

Artifacts:

| Stage | Artifact |
|------|---------|
| issue | GitHub issue |
| branch | feature branch |
| specification | spec/<issue>.md |
| design | docs/design/<issue>.md |
| implementation | src/ |
| verification | tests/ |
| PR | GitHub PR |
| cleanup | branch deletion |
| documentation | docs/ |

---

# GitHub Lifecycle Rules

1. Every change starts with a GitHub issue.
2. Every branch corresponds to one issue.
3. Never implement directly on `main`.
4. Every PR must reference the issue it resolves.
5. Merge must be followed by cleanup.

Branch format:

<type>/<issue-number>-<slug>

Examples:

feat/17-config-parser  
fix/42-cli-flags  
test/33-parser-fixtures

PR bodies must include:

Fixes #<issue>

---

# Session Workflow

start-session  
repo-state  
next-task  

If new work:

create-issue  
gh issue create  

git switch main  
git pull --ff-only  
git switch -c <type>/<issue>-slug

Then:

issue-to-spec  
spec-review  
design-review  
implementation-plan

Verification:

test-generator  
debug skills if needed

Before PR:

patch-review  
docs-sync  
preflight

PR:

git push  
gh pr create

After merge:

git switch main  
git pull --ff-only  
git branch -d <branch>  
git remote prune origin

End session:

end-session

---

# AI Skills System

.skills/

workflow/  
github/  
git/  
debug/  
quality/  
release/  
testing/

Agents should invoke skills instead of inventing workflows.

---

# Hard Constraints

Platform: Linux  
Language: C17  
Deployment: air‑gapped by default

Agents must not introduce:

- internet dependencies
- cloud APIs
- remote telemetry
- runtime dependency downloads

---

# Dependency Rules

Prefer:

1. libc / POSIX
2. small local code
3. tiny vendored libraries

Avoid:

- large dependency trees
- network‑based build steps

---

# Coding Standard

## Phase‑Oriented C

Typical phases:

validate_input  
initialize_state  
acquire_resources  
read_inputs  
transform_state  
check_invariants  
emit_results  
cleanup

`goto` allowed for cleanup and phase transitions.

Avoid deep nesting.

---

# Build Expectations

Offline friendly.

Requirements:

- make works without internet
- tests run locally
- build does not fetch dependencies

Supported compilers:

cc  
gcc  
clang

---

# Security Posture

Avoid:

- unsafe string handling
- shell injection
- hidden subprocesses
- temp file race patterns

Prefer:

- bounds checks
- argv‑style subprocess calls
- least privilege operation

---

# Commit Style

Changes must be narrow and reviewable.

Guidelines:

- one logical change per commit
- update docs with behavior changes
- small functions over monoliths
