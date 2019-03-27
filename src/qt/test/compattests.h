// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017 The Mynt Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef MYNT_QT_TEST_COMPATTESTS_H
#define MYNT_QT_TEST_COMPATTESTS_H

#include <QObject>
#include <QTest>

class CompatTests : public QObject
{
    Q_OBJECT

private Q_SLOTS:
    void bswapTests();
};

#endif // MYNT_QT_TEST_COMPATTESTS_H
