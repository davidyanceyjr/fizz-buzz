# Spec: Issue #2 Reconcile Issue #1 Planning Artifacts With Implemented CLI Slice

## Problem

The repository's Issue #1 implementation plan no longer matches the
actual code and test state. The plan still describes overflow-safe
range emission and expanded CLI edge-case shell coverage as pending
follow-on work even though those changes are already present in the
implementation.

This spec defines the repository-state reconciliation needed so that
workflow artifacts remain auditable and future contributors do not
repeat completed work.

## Context

Issue #1 regularized an already-implemented FizzBuzz CLI slice after it
landed directly on `main`. That issue now has a spec and design
artifacts, but at least one planning document still reflects an earlier
repository state.

This repository emphasizes human-auditable control flow, deterministic
behavior, and narrow, reviewable changes. Workflow artifacts are part of
that audit trail and must accurately describe what remains to be done.

## Requirements

### Artifact Reconciliation

- The repository shall review Issue #1 planning and design artifacts
  against the current implementation and shell tests.
- The repository shall update stale planning or design text that lists
  already-completed work as pending.
- The repository shall preserve Issue #1 behavior documentation unless a
  real inconsistency is found.

### Current-State Reporting

- The reconciled artifact set shall identify the current state of Issue
  #1 accurately.
- If implementation work for Issue #1 is already complete, the
  documented next action shall be a closure-oriented workflow step
  rather than a duplicate implementation task.
- Any remaining follow-up shall be stated explicitly and narrowly.

### Scope Control

- The reconciliation shall not introduce new user-facing CLI features.
- The reconciliation shall not change existing CLI output, exit status,
  or parser behavior.
- The reconciliation shall keep changes narrow, reviewable, and aligned
  with the documented repository workflow.

## Constraints

- Platform: Linux
- Language: C17
- Build and test flow must remain offline-friendly
- No runtime network access, telemetry, or dependency downloads
- Documentation changes must remain consistent with the repository's
  workflow rules in `AGENTS.md`

## Non-goals

- New feature development
- Refactoring unrelated implementation code
- Rewriting Issue #1 artifacts beyond what is needed to restore
  consistency
- Introducing new process machinery unless a concrete gap requires it

## Edge Cases

- If Issue #1 artifacts disagree with the current implementation, the
  mismatch shall be identified explicitly rather than papered over.
- If no implementation work remains for Issue #1, the repository shall
  not present coding tasks as the recommended next action.
- If closure prerequisites are still missing, those missing artifacts or
  workflow steps shall be named directly.

## Acceptance Criteria

- The relevant Issue #1 planning or design artifact no longer presents
  already-implemented work as pending.
- The documented next step for Issue #1 matches the current repository
  state.
- `README.md`, `docs/requirements.md`, `docs/specifications.md`, and
  issue-linked artifacts remain internally consistent after
  reconciliation.
- The repository continues to build and test locally without network
  access.

## Open Questions

- Should Issue #1 be closed immediately after artifact reconciliation,
  or should a separate closure step capture the unusual history of work
  that originally landed on `main`?
- Does this repository need a standing closure checklist for slices that
  are regularized after implementation?
