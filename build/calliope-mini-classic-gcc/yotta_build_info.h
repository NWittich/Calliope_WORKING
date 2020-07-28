#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 7 // UTC month 1-12
#define YOTTA_BUILD_DAY 28 // UTC day 1-31
#define YOTTA_BUILD_HOUR 6 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 28 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 0 // UTC second 0-61
#define YOTTA_BUILD_UUID c94d0edf-3360-4c5a-9680-df8f44cf8d9a // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'f20266a3656ca4df25e1a108a5499ce0c2753c60' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'f20266a' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
