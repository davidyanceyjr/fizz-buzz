Reference only.
Not required for runtime skill dispatch.

# AI + Human Pair Workflow

Canonical lifecycle:

issue -> branch -> specification -> design -> implementation -> tests -> debug -> PR -> review -> merge -> cleanup -> documentation

## Human owns

- `gh issue create`
- `git switch -c ...`
- code edits
- `git commit`
- `git push`
- `gh pr create`
- `gh pr merge`
- local cleanup

## AI owns

- issue drafting
- branch naming guidance
- specification critique
- design review
- implementation planning
- test generation
- patch review
- PR drafting
- cleanup checklist

## Session loop

1. `start-session`
2. `repo-state`
3. `github-state`
4. `next-task`
5. If new work: `issue-start` -> `create-issue` -> `branch-start`
6. `issue-to-spec`
7. `spec-review`
8. `design-review`
9. `implementation-plan`
10. human implements one slice
11. `test-generator`
12. debug skills as needed
13. `patch-review`
14. `docs-sync`
15. `preflight`
16. `pr-prep`
17. human runs `gh pr create`
18. human merges PR
19. `merge-cleanup`
20. `end-session`

## Safety rules

- never implement on `main`
- no implementation branch without an issue number
- every PR must include `Fixes #<issue>` or equivalent
- after merge, delete local branch and prune stale remote refs
