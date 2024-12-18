# Isolation Levels

## Usage

```shell
./isolation-levels.sh "<isolation-level>"
```

`isolation-level` could be:
* `"READ UNCOMMITTED"` (note, in Postgres this is treated as `"READ COMMITTED"` ([source](https://www.postgresql.org/docs/current/sql-set-transaction.html)))
* `"READ COMMITTED"`
* `"REPEATABLE READ"`
* `"SERIALIZABLE"`

## Example

```shell
./isolation-levels.sh "REPEATABLE READ"

CREATE TABLE
INSERT 0 1
ALTER DATABASE
ERROR:  could not serialize access due to concurrent update
ERROR:  could not serialize access due to concurrent update
 user_id | balance | txid_current 
---------+---------+--------------
       1 |      99 |          983
(1 row)

UPDATE 1
 user_id | balance | txid_current 
---------+---------+--------------
       1 |      98 |          986
(1 row)

UPDATE 1
ERROR:  could not serialize access due to concurrent update
ERROR:  could not serialize access due to concurrent update
ERROR:  could not serialize access due to concurrent update
ERROR:  could not serialize access due to concurrent update
ERROR:  could not serialize access due to concurrent update
 user_id | balance | txid_current 
---------+---------+--------------
       1 |      97 |          989
(1 row)

UPDATE 1
DROP TABLE
```
