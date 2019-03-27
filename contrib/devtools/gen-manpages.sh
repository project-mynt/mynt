#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

MYNTD=${MYNTD:-$SRCDIR/myntd}
MYNTCLI=${MYNTCLI:-$SRCDIR/mynt-cli}
MYNTTX=${MYNTTX:-$SRCDIR/mynt-tx}
MYNTQT=${MYNTQT:-$SRCDIR/qt/mynt-qt}

[ ! -x $MYNTD ] && echo "$MYNTD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
MYNTVER=($($MYNTCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for myntd if --version-string is not set,
# but has different outcomes for mynt-qt and mynt-cli.
echo "[COPYRIGHT]" > footer.h2m
$MYNTD --version | sed -n '1!p' >> footer.h2m

for cmd in $MYNTD $MYNTCLI $MYNTTX $MYNTQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${MYNTVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${MYNTVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
