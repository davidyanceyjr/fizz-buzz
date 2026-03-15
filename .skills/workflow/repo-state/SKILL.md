# repo-state

Purpose
-------
Analyze repository engineering state and determine workflow position.

This skill analyzes issues, specifications, design documents,
implementation status, and tests to determine where work currently
stands and what the next action should be.

Use When
--------
- beginning a session
- the repository state is unclear
- determining the next task
- reviewing project progress
- auditing workflow discipline

Inputs
------
Repository working tree
GitHub issues
spec/ directory
docs/design/ directory
src/ directory
tests/ directory
SESSION.md

Procedure
---------

1. Read AGENTS.md

Understand repository intent and development rules.

2. Inspect working tree

Run or simulate:

git status
git branch --show-current
git log --oneline -n 5

Record:
- current branch
- recent commits
- uncommitted changes

3. Inspect GitHub issues

Run:

gh issue list

Collect:
- open issues
- issue numbers
- issue titles

4. Inspect specifications

Check:

spec/

Determine which issues have specifications.

Example:

spec/012-cli-stats.md → Issue #12 spec exists

5. Inspect design documents

Check:

docs/design/

Determine which issues have design documents.

6. Inspect implementation

Check:

src/

Determine whether implementation appears:

missing
partial
complete

7. Inspect tests

Check:

tests/

Determine whether tests exist and appear relevant.

8. Build workflow table

For each issue produce:

Issue | Spec | Design | Code | Tests

Example:

#12 | yes | yes | partial | failing
#15 | yes | no  | none    | none

9. Determine workflow stage

Classify the most active issue into:

issue
spec
design
implementation
test
debug
review
docs

10. Detect workflow violations

Examples:

code exists without spec
design missing but implementation started
tests missing after implementation

11. Detect slice completion

Determine whether the active issue appears ready to move into closure work.

A slice is complete when all of the following are true:
- specification exists or the issue is otherwise clearly defined
- required design decisions are recorded
- implementation is present
- relevant tests exist
- tests appear passing or no known failing test blocks review
- no earlier-stage workflow violation is detected

If these conditions hold, mark the slice as complete and prefer the next
closure step instead of more implementation.

12. Recommend next action

Select the smallest forward step using skills such as:

issue-to-spec
design-review
implementation-plan
test-generator
patch-review
docs-sync

If the slice is complete, prefer one closure skill such as:
pr-prep
create-pr
merge-cleanup
docs-sync
end-session

Decision Rules
--------------
- Start with current branch, git status, recent commits, and issue metadata.
- Infer the active issue from the branch name first when possible.
- Inspect only files relevant to the likely active issue and stage.
- Perform a broad repository scan only if issue or stage remains unclear.
- Prefer targeted evidence over full repository summaries.
- If slice completion is detected, prefer closure work over new implementation.

Output Format
-------------

Repository State
----------------

Branch:
Recent Commits:

Open Issues
-----------

(issue list)

Workflow Table
--------------

Issue | Spec | Design | Code | Tests
----- | ---- | ------ | ---- | -----

Active Issue
------------

(issue number)

Current Stage
-------------

(workflow stage)

Problems Detected
-----------------

(list workflow violations or missing artifacts)

Slice Completion
----------------

Status: <complete or incomplete>
Reason:

Recommended Next Action
-----------------------

Skill:
Reason:
