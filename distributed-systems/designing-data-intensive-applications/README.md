# Designing Data-Intensive Applications: The Big Ideas Behind Reliable, Scalable, and Maintainable Systems

by Martin Kleppmann

## Preface

* Internet companies are handling huge volumes of data and traffic, forcing them to create new tools that enable them to efficiently handle such scale
* An application is *data-intensive* if the quantity of data, the complexity of data, or the speed at which it is changing is the primary challenge
* After reading this book, you will be in a great position to decided which kind of technology is appropriate for which purpose, and understand how tools can be combined to form the foundation of a good application architecture
* [https://github.com/ept/ddia-references](https://github.com/ept/ddia-references) contains all up-to-date links mentioned in this book

## PART 1: Foundatations of Data Systems

The first four chapters go through the fundamental ideas that apply to all data systems, whether running on a single machine or distributed across a cluster of machines.

### Chapter 1: Reliable, Scalable, and Maintainable Applications

> This chapter focuses on the meaning of *reliability*, *scalability*, *maintainability*, and how we can try to achieve these goals.

Many applications today are *data-intensive*, as opposed to *compute-intensive*. These applications need to:

* Store data so that they, or another application, can find it again later (*databases*)
* Remember the result of an expensive operation, to speed up reads (*caches*)
* Allow users to search data by keyword or filter it in various ways (*search indexes*)
* Send a message to anoter process, to be handled asynchronously (*stream processing*)
* Periodically crunch a large amount of accumulated data (*batch processing*)

#### Thinking About Data Systems

![Figure 1-1. One possible architecture for a data system that combines several components](images/ddia_figure_1-1.png)

* When building an application, we still need to figure out which tools and which approaches are the most appropriate for the task at hand. It can be hard to combine tools when you need to do something that a single tool cannot do alone.
* Increasingly many applications now have such demanding or wide-ranging requirements that a single tool can no longer meet all of its data processing and storage needs
  * Instead the work is broken down into tasks that can be performed efficiently on a single tool, and those different tools are stitched together using application code
* When you combine several tools in order to provide a service, the service's application programming interace (API) usually hides implementation details from clients
  * You have created a new, special-purpose data system from smaller, general-purpose components
  * How do you ensure that the data remains correct and complete, even when things go wrong internally?
  * How do you provide consistently good performance to clients, even when parts of your system are degraded?
  * How do you scale to handle an increase in load?
  * What does a good API for the service look like?
  * And many more tricky questions will arise when you develop your data system
