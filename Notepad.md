# Project Report: Notepad Text Editor

This report outlines the implementation of additional features for the base Qt text editor application. All modifications adhere to object-oriented programming (OOP) principles, leverage **Clang-Format** and **Clang-Tidy** globally to maintain strict code styling and static analysis standards, and follow clean code conventions.

## 1. Required Features

### Exception Handling
* **Custom Hierarchy:** Developed an exception hierarchy derived from a base `notepad_exception` class, including specific classes like `file_not_found_exception` and `file_read_exception`.
* **Robust I/O Operations:** Enclosed file reading and writing processes within `try-catch` blocks to prevent unexpected termination.
* **Error Reporting:** System errors are captured dynamically and displayed to the user via `QMessageBox::critical` dialogs.

### Spell Checker
* **Real-Time Highlighting:** Integrated real-time error detection using `QSyntaxHighlighter`.
* **Optimized Storage:** Stored dictionary data within a `std::set` container to guarantee efficient O(log n) lookup time complexity.
* **Context Menu Suggestions:** Overrode the default right-click context menu to parse the word under the cursor and return up to 5 spelling corrections.
* **Path Validation:** Added a safety check during initialization; a missing `data/words.txt` file triggers a controlled `QMessageBox::warning` rather than an application crash.
* **Manual Invocation:** Added a manual validation trigger under `Tools > Check Spelling...`.

---

## 2. Optional Features

The following features from the project requirements were successfully implemented:

1. **Cursor Position Indicator:**
   * Tracks and displays the active line and column numbers (`Ln X, Col Y`) in the status bar by monitoring the `cursorPositionChanged` signal.

2. **Font Dialog:**
   * Integrated `QFontDialog` under `Format > Font...` to modify the font family and point size of the current selection or the entire document.

3. **Color Picker:**
   * Integrated `QColorDialog` under `Format > Text Color...` to apply color changes to selected text blocks.

4. **Document Printing:**
   * Configured a `File > Print...` action bound to the standard `Ctrl+P` shortcut.
   * Uses `QPrinter` and `QPrintDialog` to render the document layout directly from the `QTextEdit` core via `editor->print()`.

5. **Text Scaling (Zoom):**
   * Implemented font scaling actions under the `View` menu using `QTextEdit::zoomIn()` and `QTextEdit::zoomOut()`.
   * Mapped shortcuts to both `Ctrl++` and `Ctrl+=` to accommodate standard keyboard layouts.

---

## 3. Additional UI/UX Features

1. **Light Mode Toggle:**
   * Added a `View > Light Mode` option (`Ctrl+L`) that switches the default dark theme palette to a light layout using `QPalette` structures.

2. **Placeholder Text:**
   * Configured default instructional text via `setPlaceholderText` that automatically hides once the user initiates document input.

3. **Anti-Spam Input Filter:**
   * Implemented an input throttle mechanism toggleable via `View > Child Protection (Anti-Spam)`.
   * Monitors the `textChanged` signal and enforces a temporary 150ms read-only lock using `QTimer::singleShot` to prevent high-frequency keyboard smashing and rapid accidental text deletion.

4. **CurrentTime Insertion:**
   * Added a time and date injection mechanism under `Edit > Time/Date` bound to the **F5** shortcut, matching traditional notepad implementations.
   * Retrieves system metrics via `QDateTime::currentDateTime()` and inserts the formatted string at the current cursor position.

5. **Strikethrough Formatting:**
   * Expanded the formatting toolbar by introducing a **Strikethrough** action backed by a custom vector graphic asset (`strikethrough.svg`).
   * Applies the formatting style using `QTextCharFormat::setFontStrikeOut` and merges it via `QTextCursor` (`Ctrl+Shift+X`).

6. **Full Screen Toggle:**
   * Added a window constraint utility under `View > Full Screen` bound to the **F11** shortcut.
   * Seamlessly switches window flags between `showFullScreen()` and `showNormal()`.