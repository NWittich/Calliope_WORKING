#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 6 // UTC month 1-12
#define YOTTA_BUILD_DAY 10 // UTC day 1-31
#define YOTTA_BUILD_HOUR 17 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 8 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 42 // UTC second 0-61
#define YOTTA_BUILD_UUID 49089b76-3a93-4249-8765-fd38ca87fe58 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'69dcb3922385d911c661f2e4fcca2e47a04ae672' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'69dcb39' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
