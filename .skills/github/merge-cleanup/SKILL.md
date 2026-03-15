# merge-cleanup

Purpose
-------
Close the GitHub lifecycle after a merge by verifying issue closure,
synchronizing the default branch, and removing stale branch state.

Use When
--------
- immediately after PR merge
- when a merged branch still exists locally
- when session state must be reset after completed work

Inputs
------
Merged PR context
Issue number
Branch name
Current local branch state
SESSION.md

Procedure
---------

1. Verify merge status

   Confirm the PR was merged, not merely opened.

2. Verify issue closure

   Check that the linked issue is closed or state that follow-up is needed.

3. Recommend cleanup commands

   Provide:

   git switch main
   git pull --ff-only
   git branch -d <branch>
   git remote prune origin

4. Check for branch deletion safety

   If the branch is not fully merged, say so clearly and do not recommend `-d`
   without warning.

5. Update session state

   Recommend resetting SESSION.md to include:
   - merged PR
   - closed issue
   - cleanup status
   - next candidate work item

6. Recommend next skill

   Usually:
   - end-session
   - repo-state
   - milestone-planner

Output Format
-------------

Merge Status
------------

PR:
Issue:
Branch:

Cleanup Commands
----------------

Exact commands to run.

SESSION.md Notes
----------------

Short post-merge summary.
