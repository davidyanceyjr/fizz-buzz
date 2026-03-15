# pr-prep

Purpose
-------
Prepare a pull request that is traceable, reviewable, and capable of closing
the intended GitHub issue on merge.

Use When
--------
- branch work is ready for review
- local tests have been run
- patch review and docs sync are complete or nearly complete

Inputs
------
Issue number
Branch name
Diff or commit summary
Test evidence
Documentation changes
Known risks or limitations

Procedure
---------

1. Verify PR readiness

   Check:
   - not on `main`
   - branch name includes issue number
   - patch-review completed
   - tests were run
   - docs updated if behavior changed

2. Summarize the change honestly

   Ground all claims in the diff and test evidence.

3. Draft PR title

   Keep it concise and scoped.

4. Draft PR body

   Include sections for:
   - Summary
   - Problem
   - Approach
   - Testing
   - Risks / Tradeoffs
   - Follow-ups

5. Require issue-closing linkage

   Include one of:
   - Fixes #<issue>
   - Closes #<issue>
   - Resolves #<issue>

6. Provide operator command

   Suggest a `gh pr create` command with title and body-file usage.

Output Format
-------------

PR Readiness
------------

Ready:
Missing items:

PR Draft
--------

Title:
Body:

Command
-------

Suggested `gh pr create` command.
