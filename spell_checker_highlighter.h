#ifndef SPELL_CHECKER_HIGHLIGHTER_H
#define SPELL_CHECKER_HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include <QRegularExpression>
#include "spell_checker.h"

class spell_checker_highlighter : public QSyntaxHighlighter {
    Q_OBJECT
public:
    spell_checker_highlighter(QTextDocument* parent, const spell_checker& checker)
        : QSyntaxHighlighter(parent), m_checker(checker)
    {
        m_error_format.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
        m_error_format.setUnderlineColor(Qt::red);
    }

protected:
    void highlightBlock(const QString& text) override {
        QRegularExpression word_regex(R"(\b[A-Za-z]+\b)");
        auto it = word_regex.globalMatch(text);

        while (it.hasNext()) {
            auto match = it.next();
            std::string word = match.captured(0).toStdString();

            if (!m_checker.is_correct(word)) {
                setFormat(match.capturedStart(), match.capturedLength(), m_error_format);
            }
        }
    }

private:
    const spell_checker& m_checker;
    QTextCharFormat m_error_format;
};

#endif // SPELL_CHECKER_HIGHLIGHTER_H