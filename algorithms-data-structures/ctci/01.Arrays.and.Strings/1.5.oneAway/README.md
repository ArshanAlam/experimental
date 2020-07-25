# One Away
### Cracking the Coding Interview 6th Ed.

Chapter 1: Arrays and Strings

Interview Question 1.5

There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.

#### Example

| String 1 | String 2 | Output |
|:---------|:---------|:------:|
| pale     | ple      | true   |
| pales    | pale     | true   |
| pale     | bale     | true   |
| pale     | pable    | true   |
| pale     | bake     | false  |
