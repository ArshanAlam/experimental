#!/bin/bash
if [ $# -eq 0 ]
then
  echo "No isolation level provided. Please read the README.md file."
  exit;
else
  isolation_level=$1
fi


PSQL_CMD="docker exec -it postgres psql -c";

$PSQL_CMD 'create table if not exists users (user_id serial primary key, balance numeric);'
$PSQL_CMD 'insert into users (balance) values (100);'

$PSQL_CMD 'alter database postgres set default_transaction_isolation to "'"$isolation_level"'";'

for i in $(seq 1 10);
do
  # We're running this in the background so we have to remove the -it from $PSQL_CMD
  docker exec postgres psql -c 'update users set balance = balance - 1 where user_id = 1 and balance > 0 returning *, txid_current();' &
done

# Wait for all the child processes to finish before dropping the table
wait

$PSQL_CMD 'drop table users;'
