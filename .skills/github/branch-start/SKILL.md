# branch-start

Purpose
-------
Create and switch to the implementation branch for a GitHub-tracked issue.
Work must never proceed on `main`.

Branch naming MUST follow AGENTS.md.

Format
------
<type>/<issue-number>-<slug>

Examples
--------
feat/17-config-parser
fix/42-cli-flags
test/33-parser-fixtures

Use When
--------
- an issue exists
- specification or design work is complete
- implementation is about to begin

Procedure
---------
1. Identify the active issue number.
2. Generate a short descriptive slug.
3. Choose an appropriate type prefix (feat, fix, test, docs, refactor, chore).
4. Construct the branch name:

   <type>/<issue-number>-<slug>

5. Create the branch safely:

   git switch main
   git pull --ff-only
   git switch -c <type>/<issue-number>-<slug>

6. If the branch already exists:

   git switch <type>/<issue-number>-<slug>

Decision Rules
--------------
- Branch name must map clearly to the issue.
- Do not work directly on main.
- Branch naming must match AGENTS.md exactly.

Output
------
Return:

Current Branch: <type>/<issue-number>-<slug>
Active Issue: <issue-number>
Next Step: implementation
