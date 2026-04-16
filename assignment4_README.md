# Assignment 4 — Implementation Line Map

- Setup / dependencies: Lines 1-2
  - `!pip install pandas numpy`

- Imports: Lines 4-6
  - `import uuid`, `import json`, `from datetime import datetime, timedelta`

- `Application` class: Lines 8-17
  - DEFAULT_PERMS and class creating Permission objects and per-application attributes

- `Permission` class: Lines 20-24
  - Name, action, and application

- `Role` class: Lines 26-41
  - role name, parent relationship, add_permission(s), and get_all_permissions (handles inheritance)

- `User` class (construction and role assignment): Lines 44-56
  - id generation, roles list, assign_role with 4 role limit

- `User` session management: Lines 58-70
  - get_active_role(), start_session(role_name) and session_start timestamp

- `User` logging helpers: Lines 72-83
  - log_attempt(...) writes JSON lines to `access_log.json`

- `User` access checking: Lines 84-106
  - check_access(app_name, action): verifies active session, session expiry, permission check, logs results

- Seeding: Lines 107-150
  - Create applications, permissions, roles with inheritance, and users with role assignments

- Scenario 1: Successful inheritance: Lines 153-158
  - Create `u1`, assign role C, start session, check access

- Scenario 2: Access Denied (Unauthorized): Lines 160-162
  - `u1` attempts RMS.Approve

- Scenario 3: Unauthorized Role Selection: Lines 164-169
  - `u2` assigned role G then attempts to start session with role A

- Scenario 4: Attempt to access without active session: Lines 170-175
  - `u3` assigned role A but does not start session before check_access

- Scenario 5: Session expired: Lines 177-184
  - `u4` assigned role B, starts session, session_start set back 2 hours, check_access



