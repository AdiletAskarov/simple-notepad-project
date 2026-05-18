# Project Report: Notepad Text Editor

This project adds new features to the base Qt text editor application. All modifications are implemented using standard OOP principles and clean code styling.

## 1. Required Features

### Exception Handling
- Created a custom exception hierarchy based on the `notepad_exception` base class (including `file_not_found_exception` for file I/O errors).
- Wrapped file opening and saving operations in `try-catch` blocks.
- Errors are caught properly and displayed to the user via a `QMessageBox::critical` dialog.

### Spell Checker
- Integrated real-time spell-checking using `QSyntaxHighlighter`.
- Stored the dictionary words in a `std::set` container to ensure fast lookups with O(log n) time complexity.
- Implemented a custom right-click context menu that suggests up to 5 words for misspelled text.
- Added a safety check for loading the dictionary file (`data/words.txt`). If the file is missing, the application shows a `QMessageBox::warning` instead of crashing.
- Added a manual check option under `Tools > Check Spelling...` to re-verify the text on demand.

## 2. Optional Features

The following optional features from the project requirements were implemented:

1. **Cursor Position Indicator:**
    - Added a label to the status bar that tracks the current line and column (`Ln X, Col Y`) in real-time using the `cursorPositionChanged` signal.

2. **Font Dialog:**
    - Added `Format > Font...` using `QFontDialog` to change the text font for the selection or the whole document.

3. **Color Picker:**
    - Added `Format > Text Color...` using `QColorDialog` to let users change the text color.

4. **Text Scaling (Zoom In / Zoom Out):**
    - Added Zoom In and Zoom Out actions under the `View` menu using `QTextEdit`'s built-in `zoomIn()` and `zoomOut()` methods.
    - Configured shortcuts to display `Ctrl++` in the menu, but also support `Ctrl+=` so users can zoom in without holding the `Shift` key.

## 3. Extra Features (Bonus UI/UX)

1. **Light Mode Toggle:**
    - Added a `View > Light Mode` option. Since the application opens in a dark theme by default, this toggle switches the window and editor colors to a light layout using `QPalette`. Turning it off restores the original dark theme.

2. **Placeholder Text:**
    - Added a text prompt using `setPlaceholderText("Start typing here or open a file...")` that shows up when the text editor is empty and disappears when typing begins.