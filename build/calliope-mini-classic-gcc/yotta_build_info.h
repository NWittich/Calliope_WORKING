#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2020 // UTC year
#define YOTTA_BUILD_MONTH 7 // UTC month 1-12
#define YOTTA_BUILD_DAY 27 // UTC day 1-31
#define YOTTA_BUILD_HOUR 9 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 32 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 0 // UTC second 0-61
#define YOTTA_BUILD_UUID 2fad1646-bb5c-431e-9a73-25e701cc315c // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID b'841fbd614e9f3bf4a03e9daace9da0ce6ebed7f7' // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION b'841fbd6' // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
