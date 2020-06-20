#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 20 // UTC day 1-31
#define YOTTA_BUILD_HOUR 19 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 12 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 19 // UTC second 0-61
#define YOTTA_BUILD_UUID 4436e840-b4ba-437e-88ea-1bac3f5d831a // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'c11da4874c1efb84c42558af3cac1b9e7238afce' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'c11da48' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
