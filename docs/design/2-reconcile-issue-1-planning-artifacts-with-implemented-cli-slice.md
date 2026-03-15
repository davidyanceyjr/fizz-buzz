# Design Review: Issue #2 Reconcile Issue #1 Planning Artifacts With Implemented CLI Slice

## Design Summary

This issue is a documentation-state reconciliation task, not an
implementation redesign. The correct design is to compare Issue #1
workflow artifacts against the current repository state, correct the
stale planning text, and leave working code and tests unchanged.

The smallest meaningful change is expected to be an update to the Issue
#1 implementation plan so its goal, slices, and recommended next action
reflect the code and shell coverage that already exist.

## Scope and Boundaries

Primary artifacts in scope:

- `docs/design/1-track-fizzbuzz-teaching-tool-cli-slice-implementation-plan.md`
- related Issue #1 spec/design documents only if consistency requires a
  matching wording update
- top-level behavior documents only if an actual mismatch is found

Out of scope:

- `src/` code changes
- new CLI behavior
- test expansion unless reconciliation reveals a real gap

## Data Sources

The review should treat the current repository contents as the source of
truth for implementation state:

- `src/output.c` for sequence emission behavior
- `tests/basic.sh` for shell-level acceptance coverage
- existing Issue #1 spec and design files for artifact consistency

The reconciliation should be evidence-driven. If a document says work is
pending, that claim must be checked against current code and tests
before being preserved.

## Failure Handling

There are two valid outcomes:

1. The implementation plan is stale and should be updated to reflect
   completed work and closure-oriented next steps.
2. A real inconsistency exists between code, tests, and artifacts, in
   which case the inconsistency should be named explicitly and carried
   forward as the actual remaining task.

The design should not hide disagreement between artifacts and code.

## Risks

- The main risk is over-correcting by rewriting multiple documents when
  only the implementation plan is stale.
- A second risk is treating “already implemented on `main`” as normal
  workflow completion without documenting the remaining closure step.
- There is also a reviewability risk if the reconciliation issue drifts
  into process redesign instead of fixing the concrete mismatch.

## Alternatives Considered

### Update only the recommended next action

Too narrow if the slice descriptions themselves still describe completed
work as pending. This would leave stale context in the same file.

### Rewrite all Issue #1 artifacts

Not recommended. That adds churn without clear value and makes the
change harder to audit.

### Open a new implementation issue instead of reconciling artifacts

Not recommended. The identified defect is in the workflow record, not in
the current CLI behavior.

## Testing Implications

- `make test` remains the verification command because the issue must
  preserve current behavior while reconciling documents.
- No new tests are required unless the review uncovers an actual
  behavior gap that the current artifacts missed.

## Assumptions

- `src/output.c` already contains the overflow-safe stop-before-
  increment logic described in later Issue #1 review artifacts.
- `tests/basic.sh` already covers the CLI edge cases called out as
  pending in the stale implementation plan.
- The repository wants closure-oriented workflow guidance once a slice's
  implementation work is complete.

## Recommended Approach

Update the Issue #1 implementation plan as the primary artifact of
record. Mark the overflow and shell-coverage slices as completed history
or resolved concerns, preserve the optional refactor slice only if it is
still justified, and replace the coding-oriented next action with the
correct closure-oriented workflow step.
