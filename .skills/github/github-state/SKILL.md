# github-state

Purpose
-------
Inspect the relationship between issue, branch, commits, and pull request so
that repository work remains traceable from start to finish.

Use When
--------
- repository state is unclear
- starting or resuming a session
- before opening a PR
- after merge when cleanup may be pending

Inputs
------
Current branch
GitHub issues
GitHub pull requests
Recent commits
SESSION.md

Procedure
---------

1. Identify current branch

2. Identify active issue

   Infer from branch name, commits, or session notes.

3. Inspect PR state

   Determine whether there is:
   - no PR
   - an open PR
   - a merged PR
   - a closed unmerged PR

4. Check traceability

   Answer explicitly:
   - Does the branch map to an issue?
   - Does the PR map to the same issue?
   - Will merge close the issue?
   - Is cleanup pending?

5. Detect lifecycle problems

   Examples:
   - working on main
   - branch with no issue
   - PR body missing closing keyword
   - merged PR with stale local branch

6. Recommend the smallest next step

   Choose from:
   - issue-start
   - branch-start
   - pr-prep
   - merge-cleanup
   - end-session

Output Format
-------------

GitHub Lifecycle State
----------------------

Branch:
Issue:
PR:

Traceability Check
------------------

Issue linked:
PR linked:
Auto-close configured:
Cleanup pending:

Problems Detected
-----------------

List problems.

Recommended Next Action
-----------------------

Skill:
Reason:
