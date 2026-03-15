# issue-start

Purpose
-------
Start a tracked unit of work by turning a rough idea into a GitHub issue,
a branch recommendation, and the initial artifact plan.

Use When
--------
- beginning new feature work
- beginning a bugfix that should be tracked
- converting an ad hoc idea into reviewable repository work

Inputs
------
Problem statement
Repository naming conventions
AGENTS.md
Relevant specs or design notes if they already exist

Procedure
---------

1. Restate the work clearly

   Produce:
   - concise title
   - problem statement
   - scope
   - non-goals
   - acceptance criteria

2. Draft the GitHub issue body

   Include sections for:
   - Problem
   - Why it matters
   - Scope
   - Non-goals
   - Acceptance criteria
   - Constraints
   - Open questions

3. Recommend a branch name

   Use repository convention:

   <type>/<issue-number>-<slug>

   If the issue number does not exist yet, use a placeholder form and state
   that the real branch name must be created after `gh issue create`.

4. Recommend artifact paths

   Provide likely paths such as:
   - spec/<issue>.md
   - docs/design/<issue>.md

5. Recommend the next skills

   Usually:
   - issue-to-spec
   - spec-review
   - design-review

6. Provide operator commands

   Suggest:
   - `gh issue create --title ... --body-file ...`
   - the follow-up branch command after the issue number is known

Output Format
-------------

Issue Draft
-----------

Title:
Body:

Branch Recommendation
---------------------

Temporary branch name or final branch name.

Artifact Plan
-------------

Spec path:
Design path:

Next Skills
-----------

Skill:
Reason:
