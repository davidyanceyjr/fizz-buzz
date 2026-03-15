# next-task

Purpose
-------
Select the next correct step in the engineering workflow.

This skill does NOT re-scan the repository. It consumes the latest
repo-state summary and determines the smallest valid forward step.

Inputs
------
- active issue
- current branch
- workflow stage
- artifact status (spec/design/code/tests)
- test results
- workflow violations
- slice completion status

Procedure
---------
1. Read the most recent repo-state summary.
2. Determine the current workflow stage.
3. Identify the smallest valid forward step.
4. If the current slice is complete, recommend finish-oriented closure work.
5. Recommend exactly one skill to run next.

Decision Rules
--------------
- Never skip workflow stages.
- Prefer the smallest forward progress step.
- If artifacts are missing, recommend creating them.
- If the slice is complete, prefer the next closure step over new implementation.
- Report the missing artifact or blocking condition that justifies the recommendation.

Output
------
Return:

Issue: <issue number or none>
Branch: <branch name>
Stage: <stage>
Next Skill: <skill>
Missing Artifact: <artifact, blocker, or none>
Reason: <one sentence>

If the slice is complete, the next skill should point into closure work such as:
- pr-prep
- create-pr
- merge-cleanup
- docs-sync
- end-session
