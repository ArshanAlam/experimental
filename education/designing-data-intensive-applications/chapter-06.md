# Designing Data-Intensive Applications
## Chapter 06 - Partitioning

* Partitioning (also known as sharding) is the breaking up of very large datasets or very high query throughput.
* Each partition is a small database of its own, although the database may support operations that touch multiple paritions at the same time
* Main reason for wanting to partition data is scalability
* Large dataset can be distributed across many disks, and the query load can be distributed across many processors
* For queries that operate on a single partition, each ndoe can independently execute the queries on its own partition
  * Query throughput can be scaled by adding more nodes


### Partitioning and Replication
* Partitioning is usually combined with replication so that copies of each partition are stored on multiple nodes
  * Record that belongs to one partition could be stored on several different nodes for fault tolerance
* Each node may be the leader for some partitions and a follower for other partitions
* The choice of partitioning scheme is mostly independent of the choice of replication scheme

![Figure 6-1](images/figure-6-1.png)



### Partitioning of Key-Value Data
* Say you have a lage amount of data, and you want to partition it.
  * How do you decide which records to store on which nodes?
* Our goal with partitioning is to spread the data and the query load evenly across nodes
  * *In theory 10 nodes should be able to handle 10 times as much data and 10 times the read and write throughput of a single node*
* If the partitioning is unfair, so that some partitions have more data or queries than others, we call it **skewed**
  * A partition with disproportionately high load is called a **hot spot**

#### Partitioning by Key Range
* Let's assume for now that you have a simple key-value data model, in which you always access a record by its primary key.
* One way of partitioning is to assign a continuous range of keys to each partition
* If you know the boundaries between the ranges, you can easily determine which partition contains a given key
* If you also know which partition is assignws to which node, then you can make your request directly to the appropriate node
* The ranges of the keys are not necessarily evenly spaced (i.e., Volume 1 is from A->B and Volume 12 is from T->Z)
* In order to distribute the data evenly, the partition boundaries need to adapt to the data
  * Boundaries could be chosen manually by an administrator, or the database can choose them automatically
* Within each partition, we can keep keys in sorted order (STables and LSM-Trees)
  * Upside; range scans are easy (i.e., Fetching data that use timestamp as the key)
  * Downside; certain access patterns can lead to hot spots


![Figure 6-2](images/figure-6-2.png)


#### Partitioning by Hash of Key
* Because of this risk of skew and hot spots, many distributed datasources use a hash function to determine the partition for a given key
* A good hash function takes skewed data andmakes it uniformly distributed
  * The hash function need not be cryptographically strong
  * Cassandra and MongoDB use **MD5**
* Many programming languages have simple hash functions built in (i.e., Java `Object.hashCode()`)
* Once you have a suitable hash function for keys, you can assign each partition a range of hashes (rather than a range of keys)
  * Every key whose hash falls within a partition's range will be stored in that partition
* This technique is good at distributing keys fairly among the partitions
* By using hash of the key for partitioning we lose the ability to do efficient range queries
  * Keys that were once adjacent (in key-range partitioning) are now scattered across all the partitions, so their sort order is lost


![Figure 6-3](images/figure-6-3.png)



##### Consistent Hashing
* A way of evenly distributing load across an internet-wide system of caches such as a content delivery network (CDN).
* It uses randomly chosen partition boundaries to avoid the need for central control or distributed consensus
* This particular approach actually doesn't work very well for databases
  * It is rarely used in practice and the documentation of some databases (i.e., Cassandra) still refer to consistent hashing, but it is often inaccurate



#### Skewed Workloads and Relieving Hot Spots
* In extreme cases where all reads and writes are for the same key, you still end up with all requests being routed to the same partition
  * A celebrity/politician (i.e., POTUS) with millions of followers may cause a storm of activity when they do something
* Hashing the key (i.e., user ID of the celebrity) doesn't help, as the hash of two identical IDs is still the same
* Even today, most data systems are not able to automatically compensate for such a highly skewed workload, so it's the responsibility of the application to reduce the skew
* We could split **hot** keys by appending a random number
  * We'll need some way of keeping track of which keys are being split
* Perhaps in the future, data systems will be able to automatically detect and compensate for skewed workloads, but for now, you need to think through the trade-offs for your own application





### Partitioning and Secondary Indexes

#### Partitioning Secondary Indexes by Document

#### Partitioning Secondary Indexes by Term

### Rebalancing Partitions

#### Strategies for Rebalancing
