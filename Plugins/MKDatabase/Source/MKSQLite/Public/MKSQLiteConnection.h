// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MKSQLite.h"

class MKSQLiteDataReader;
class MKSQLiteParameter;

/*
** CAPI3REF: Result Codes
** KEYWORDS: {result code definitions}
**
** Many SQLite functions return an integer result code from the set shown
** here in order to indicate success or failure.
**
** New error codes may be added in future versions of SQLite.
**
** See also: [extended result code definitions]
*/
#define MKSQLITE_OK           0   /* Successful result */
/* beginning-of-error-codes */
#define MKSQLITE_ERROR        1   /* Generic error */
#define MKSQLITE_INTERNAL     2   /* Internal logic error in SQLite */
#define MKSQLITE_PERM         3   /* Access permission denied */
#define MKSQLITE_ABORT        4   /* Callback routine requested an abort */
#define MKSQLITE_BUSY         5   /* The database file is locked */
#define MKSQLITE_LOCKED       6   /* A table in the database is locked */
#define MKSQLITE_NOMEM        7   /* A malloc() failed */
#define MKSQLITE_READONLY     8   /* Attempt to write a readonly database */
#define MKSQLITE_INTERRUPT    9   /* Operation terminated by sqlite3_interrupt()*/
#define MKSQLITE_IOERR       10   /* Some kind of disk I/O error occurred */
#define MKSQLITE_CORRUPT     11   /* The database disk image is malformed */
#define MKSQLITE_NOTFOUND    12   /* Unknown opcode in sqlite3_file_control() */
#define MKSQLITE_FULL        13   /* Insertion failed because database is full */
#define MKSQLITE_CANTOPEN    14   /* Unable to open the database file */
#define MKSQLITE_PROTOCOL    15   /* Database lock protocol error */
#define MKSQLITE_EMPTY       16   /* Not used */
#define MKSQLITE_SCHEMA      17   /* The database schema changed */
#define MKSQLITE_TOOBIG      18   /* String or BLOB exceeds size limit */
#define MKSQLITE_CONSTRAINT  19   /* Abort due to constraint violation */
#define MKSQLITE_MISMATCH    20   /* Data type mismatch */
#define MKSQLITE_MISUSE      21   /* Library used incorrectly */
#define MKSQLITE_NOLFS       22   /* Uses OS features not supported on host */
#define MKSQLITE_AUTH        23   /* Authorization denied */
#define MKSQLITE_FORMAT      24   /* Not used */
#define MKSQLITE_RANGE       25   /* 2nd parameter to sqlite3_bind out of range */
#define MKSQLITE_NOTADB      26   /* File opened that is not a database file */
#define MKSQLITE_NOTICE      27   /* Notifications from sqlite3_log() */
#define MKSQLITE_WARNING     28   /* Warnings from sqlite3_log() */
#define MKSQLITE_ROW         100  /* sqlite3_step() has another row ready */
#define MKSQLITE_DONE        101  /* sqlite3_step() has finished executing */
/* end-of-error-codes */

/*
** CAPI3REF: Extended Result Codes
** KEYWORDS: {extended result code definitions}
**
** In its default configuration, SQLite API routines return one of 30 integer
** [result codes].  However, experience has shown that many of
** these result codes are too coarse-grained.  They do not provide as
** much information about problems as programmers might like.  In an effort to
** address this, newer versions of SQLite (version 3.3.8 [dateof:3.3.8]
** and later) include
** support for additional result codes that provide more detailed information
** about errors. These [extended result codes] are enabled or disabled
** on a per database connection basis using the
** [sqlite3_extended_result_codes()] API.  Or, the extended code for
** the most recent error can be obtained using
** [sqlite3_extended_errcode()].
*/
#define MKSQLITE_IOERR_READ              (MKSQLITE_IOERR | (1<<8))
#define MKSQLITE_IOERR_SHORT_READ        (MKSQLITE_IOERR | (2<<8))
#define MKSQLITE_IOERR_WRITE             (MKSQLITE_IOERR | (3<<8))
#define MKSQLITE_IOERR_FSYNC             (MKSQLITE_IOERR | (4<<8))
#define MKSQLITE_IOERR_DIR_FSYNC         (MKSQLITE_IOERR | (5<<8))
#define MKSQLITE_IOERR_TRUNCATE          (MKSQLITE_IOERR | (6<<8))
#define MKSQLITE_IOERR_FSTAT             (MKSQLITE_IOERR | (7<<8))
#define MKSQLITE_IOERR_UNLOCK            (MKSQLITE_IOERR | (8<<8))
#define MKSQLITE_IOERR_RDLOCK            (MKSQLITE_IOERR | (9<<8))
#define MKSQLITE_IOERR_DELETE            (MKSQLITE_IOERR | (10<<8))
#define MKSQLITE_IOERR_BLOCKED           (MKSQLITE_IOERR | (11<<8))
#define MKSQLITE_IOERR_NOMEM             (MKSQLITE_IOERR | (12<<8))
#define MKSQLITE_IOERR_ACCESS            (MKSQLITE_IOERR | (13<<8))
#define MKSQLITE_IOERR_CHECKRESERVEDLOCK (MKSQLITE_IOERR | (14<<8))
#define MKSQLITE_IOERR_LOCK              (MKSQLITE_IOERR | (15<<8))
#define MKSQLITE_IOERR_CLOSE             (MKSQLITE_IOERR | (16<<8))
#define MKSQLITE_IOERR_DIR_CLOSE         (MKSQLITE_IOERR | (17<<8))
#define MKSQLITE_IOERR_SHMOPEN           (MKSQLITE_IOERR | (18<<8))
#define MKSQLITE_IOERR_SHMSIZE           (MKSQLITE_IOERR | (19<<8))
#define MKSQLITE_IOERR_SHMLOCK           (MKSQLITE_IOERR | (20<<8))
#define MKSQLITE_IOERR_SHMMAP            (MKSQLITE_IOERR | (21<<8))
#define MKSQLITE_IOERR_SEEK              (MKSQLITE_IOERR | (22<<8))
#define MKSQLITE_IOERR_DELETE_NOENT      (MKSQLITE_IOERR | (23<<8))
#define MKSQLITE_IOERR_MMAP              (MKSQLITE_IOERR | (24<<8))
#define MKSQLITE_IOERR_GETTEMPPATH       (MKSQLITE_IOERR | (25<<8))
#define MKSQLITE_IOERR_CONVPATH          (MKSQLITE_IOERR | (26<<8))
#define MKSQLITE_IOERR_VNODE             (MKSQLITE_IOERR | (27<<8))
#define MKSQLITE_IOERR_AUTH              (MKSQLITE_IOERR | (28<<8))
#define MKSQLITE_LOCKED_SHAREDCACHE      (MKSQLITE_LOCKED |  (1<<8))
#define MKSQLITE_BUSY_RECOVERY           (MKSQLITE_BUSY   |  (1<<8))
#define MKSQLITE_BUSY_SNAPSHOT           (MKSQLITE_BUSY   |  (2<<8))
#define MKSQLITE_CANTOPEN_NOTEMPDIR      (MKSQLITE_CANTOPEN | (1<<8))
#define MKSQLITE_CANTOPEN_ISDIR          (MKSQLITE_CANTOPEN | (2<<8))
#define MKSQLITE_CANTOPEN_FULLPATH       (MKSQLITE_CANTOPEN | (3<<8))
#define MKSQLITE_CANTOPEN_CONVPATH       (MKSQLITE_CANTOPEN | (4<<8))
#define MKSQLITE_CORRUPT_VTAB            (MKSQLITE_CORRUPT | (1<<8))
#define MKSQLITE_READONLY_RECOVERY       (MKSQLITE_READONLY | (1<<8))
#define MKSQLITE_READONLY_CANTLOCK       (MKSQLITE_READONLY | (2<<8))
#define MKSQLITE_READONLY_ROLLBACK       (MKSQLITE_READONLY | (3<<8))
#define MKSQLITE_READONLY_DBMOVED        (MKSQLITE_READONLY | (4<<8))
#define MKSQLITE_ABORT_ROLLBACK          (MKSQLITE_ABORT | (2<<8))
#define MKSQLITE_CONSTRAINT_CHECK        (MKSQLITE_CONSTRAINT | (1<<8))
#define MKSQLITE_CONSTRAINT_COMMITHOOK   (MKSQLITE_CONSTRAINT | (2<<8))
#define MKSQLITE_CONSTRAINT_FOREIGNKEY   (MKSQLITE_CONSTRAINT | (3<<8))
#define MKSQLITE_CONSTRAINT_FUNCTION     (MKSQLITE_CONSTRAINT | (4<<8))
#define MKSQLITE_CONSTRAINT_NOTNULL      (MKSQLITE_CONSTRAINT | (5<<8))
#define MKSQLITE_CONSTRAINT_PRIMARYKEY   (MKSQLITE_CONSTRAINT | (6<<8))
#define MKSQLITE_CONSTRAINT_TRIGGER      (MKSQLITE_CONSTRAINT | (7<<8))
#define MKSQLITE_CONSTRAINT_UNIQUE       (MKSQLITE_CONSTRAINT | (8<<8))
#define MKSQLITE_CONSTRAINT_VTAB         (MKSQLITE_CONSTRAINT | (9<<8))
#define MKSQLITE_CONSTRAINT_ROWID        (MKSQLITE_CONSTRAINT |(10<<8))
#define MKSQLITE_NOTICE_RECOVER_WAL      (MKSQLITE_NOTICE | (1<<8))
#define MKSQLITE_NOTICE_RECOVER_ROLLBACK (MKSQLITE_NOTICE | (2<<8))
#define MKSQLITE_WARNING_AUTOINDEX       (MKSQLITE_WARNING | (1<<8))
#define MKSQLITE_AUTH_USER               (MKSQLITE_AUTH | (1<<8))
#define MKSQLITE_OK_LOAD_PERMANENTLY     (MKSQLITE_OK | (1<<8))

struct sqlite3_stmt;
struct sqlite3;

/**
 * 
 */
class MKSQLiteConnection : public IMKDatabaseConnection, public TSharedFromThis<MKSQLiteConnection>
{
	friend class MKSQLiteCommand;
	FString ConnectString;
	sqlite3 *db;

public:
	MKSQLiteConnection() {}
	MKSQLiteConnection(const FString& InConnectString);
	~MKSQLiteConnection();

public:
	// implement interface IMKDatabaseConnection
	virtual bool Open() override;
	virtual void Close() override;

	virtual TSharedPtr<IMKDatabaseCommand> CreateCommand(const FString& InSQL, const TArray<TSharedPtr<IMKDatabaseParameter>>& InParams) override;

	virtual TSharedPtr<IMKDatabaseParameter> CreateParameter(const FString& name) override;
};
