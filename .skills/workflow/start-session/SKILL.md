# start-session

Purpose
-------
Bootstrap a development session and restore workflow context.

This skill prepares SESSION.md and delegates full repository analysis
to repo-state.

Procedure
---------
1. Read AGENTS.md to understand project rules.
2. Ensure SESSION.md exists.
3. Append a new session entry with date/time.
4. Capture minimal repository facts:

   git status --short
   git branch --show-current

5. Run repo-state to determine full engineering status.
6. Record the following in SESSION.md:

   - Branch
   - Active Issue
   - Workflow Stage
   - Last Action
   - Next Step
   - Blockers

7. Recommend the next skill.

Output
------
Return:

Current Branch
Active Issue
Workflow Stage
Recommended Next Skill
