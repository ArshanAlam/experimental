CREATE DATABASE db;

-- Connect to the database
\c db;
-- Create tables
CREATE TABLE IF NOT EXISTS users (
  id uuid DEFAULT gen_random_uuid (),
  email varchar(320) NOT NULL UNIQUE,
  PRIMARY KEY (id)
);

-- Insert default values
INSERT INTO users (
  email)
VALUES (
  'admin@mydomain.io');

