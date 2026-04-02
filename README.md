# Assignment 3 README

This README shows where each implementation step

## Implementation Lines

- **Setup / dependencies** -- Lines **1-8**
  - Installs and notes for `pandas`, `numpy`, and `argon2-cffi`.

- **Imports** -- Lines **12-22**
  - Imports required libraries.

- **Constants** -- Lines **24-30**
  - Defines `DB_FILE`, `MAX_ATTEMPTS`, `LOCKOUT_DURATION`, and `OTP_EXPIRY`.

- **Defines file helpers** -- Lines **33-45**
  - Implements `load_user_data()` and `save_user_data()`.

- **Register user function** -- Lines **48-77**
  - Implements `register_user(username, password)`.
  - Checks for duplicate usernames and password requirements.

- **Login and lockout handling** -- Lines **80-121**
  - Implements `login_user(username, password)`.
  - Checks if user exists, verifies password, handles failed logins and lockouts.

- **TOTP generation and verification** -- Lines **124-165**
  - Implements `generate_totp(username)`.
  - Implements `verify_totp(username, input_otp)`.

- **Menu display** -- Lines **169-177**
  - Implements `print_menu()` and displays the available choices.

- **Main menu loop and user actions** -- Lines **180-276**
  - Implements `main()`.
  - Handles user input for the menu options

- **Exit option** -- Lines **271-274**
  - Ends the program when the user types the exit option.
