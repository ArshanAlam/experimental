/**
 * Threads and Locks
 *
 * Thread and lock examples using Java
 *
 * CTCI 6e Chapter 15
 */

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Creating thread by implementing the Runnable interface.
 */
class RunnableThreadExample implements Runnable {
  public int count = 0;

  public void run() {
    System.out.println("RunnableThreadExample starting.");
    try {
      while (count++ < ThreadExample.MAX_COUNT) {
        Thread.sleep(ThreadExample.MAX_DELAY_SEC);
        System.out.println("RunnableThreadExample count = " + count);
      }
    } catch (InterruptedException exc) {
      System.out.println("RunnableThreadExample interrupted.");      
    } // try...catch
    System.out.println("RunnableThreadExample terminating.");
  } // run()
} // RunnableThreadExample


/**
 * Example of threads by extending the thread class.
 */
class ExtendThreadExample extends Thread {
  int count = 0;
  
  public void run() {
    System.out.println("ExtendThreadExample starting.");
    try {
      while (count++ < ThreadExample.MAX_COUNT) {
        Thread.sleep(ThreadExample.MAX_DELAY_SEC);
        System.out.println("ExtendThreadExample count = " + count);
      }
    } catch (InterruptedException exc) {
      System.out.println("ExtendThreadExample interrupted.");      
    } // try...catch
    System.out.println("ExtendThreadExample terminating.");
  } // run()
} // ExtendThreadExample


/**
 * SynchronizedClassExample
 *
 * Example of using synchroized keyword to synchroize threads.
 */
class SynchronizedClassExample {
  public void foo(String name) {
    try {
      System.out.println("foo: Thread " + name + " starting.");
      Thread.sleep(ThreadExample.MAX_DELAY_SEC);
      System.out.println("foo: Thread " + name + " ending.");

      /**
       * A synchronized block of code. Two threads operating
       * on this object cannot execute the following code in
       * parallel.
       */
      synchronized(this) {
        System.out.println("foo: Thread " + name + " inside synchronized block.");
      }
    } catch(InterruptedException exc) {
      System.out.println("foo: Thread " + name + " interrupted.");
    } // try...catch
  } // foo
  
  public static synchronized void fooStatic(String name) {
    try {
      System.out.println("fooStatic: Thread " + name + " starting.");
      Thread.sleep(ThreadExample.MAX_DELAY_SEC);
      System.out.println("fooStatic: Thread " + name + " ending.");
    } catch (InterruptedException exc) {
      System.out.println("fooStatic: Thread " + name + " interrupted.");
    } // try...catch
  } // fooStatic

  public static synchronized void barStatic(String name) {
    try {
      System.out.println("barStatic: Thread " + name + " starting.");
      Thread.sleep(ThreadExample.MAX_DELAY_SEC);
      System.out.println("barStatic: Thread " + name + " ending.");
    } catch (InterruptedException exc) {
      System.out.println("barStatic: Thread " + name + " interrupted.");
    } // try...catch
  } // barStatic
} // SynchronizedClassExample


class SynchronizedClassCaller extends Thread {
  private String name;
  private SynchronizedClassExample scx;
  public SynchronizedClassCaller(String name, SynchronizedClassExample scx) {
    this.name = name;
    this.scx = scx;
  }

  public void run() {
    this.scx.foo(this.name);
    this.scx.fooStatic(this.name);
    this.scx.barStatic(this.name);
  }
} // SynchronizedClassCaller


/**
 * Example of using locks on shared resources.
 */
class LockedATM {
  private Lock lock;
  private int balance = 100;

  public LockedATM() {
    lock = new ReentrantLock();
  }

  public int withdraw(int value) {
    lock.lock();
    int tmp = this.balance;
    try {
      Thread.sleep(ThreadExample.MAX_DELAY_SEC);
      tmp -= value;
      Thread.sleep(ThreadExample.MAX_DELAY_SEC);
      this.balance = tmp;
      System.out.println("Withdraw of $" + value + " complete. New Balance = $" + this.balance);
    } catch (InterruptedException e) {
      System.out.println("LockedATM withdraw interrupted.");
    } // try...catch
    lock.unlock();
    return tmp;
  } // withdraw
  
  public int deposit(int value) {
    lock.lock();
    int tmp = this.balance;
    try {
      Thread.sleep(ThreadExample.MAX_DELAY_SEC);
      tmp += value;
      Thread.sleep(ThreadExample.MAX_DELAY_SEC);
      this.balance = tmp;
      System.out.println("Deposit of $" + value + " complete. New Balance = $" + this.balance);
    } catch (InterruptedException e) {
      System.out.println("LockedATM withdraw interrupted.");
    } // try...catch
    lock.unlock();
    return tmp;
  } // deposit
} // LockedATM


public class ThreadExample {
  public static final int MAX_COUNT = 8;
  public static final int MAX_DELAY_SEC = 512;

  public static void main(String[] args) {
    /**
     * Thread Examples
     */
    System.out.println("\nExample of threads by implementing Runnable or extending Thread\n");
    
    RunnableThreadExample rtx = new RunnableThreadExample();
    ExtendThreadExample etx = new ExtendThreadExample();
    Thread thread1 = new Thread(rtx);
    thread1.start();
    etx.start();
    
    /**
     * Wait for rtx to count to MAX_COUNT and etx to count to MAX_COUNT
     */
    while((rtx.count < ThreadExample.MAX_COUNT) || (etx.count < ThreadExample.MAX_COUNT)) {
      try {
        Thread.sleep(ThreadExample.MAX_DELAY_SEC / 2);
      } catch (InterruptedException exc) {
        exc.printStackTrace();
      } // try...catch
    } // while

    
    /**
     * Synchronized class Example
     */
    System.out.println("\nExample of synchronization\n");
    SynchronizedClassExample scx1 = new SynchronizedClassExample();
    SynchronizedClassExample scx2 = new SynchronizedClassExample();
    new SynchronizedClassCaller("SCC 1", scx1).start();
    new SynchronizedClassCaller("SCC 3 using reference to scx1", scx1).start();
    new SynchronizedClassCaller("SCC 2", scx2).start();
    
    /**
     * Lock example for shared resources.
     */
    System.out.println("\nLock example for shared resources.\n");
    LockedATM atm = new LockedATM();
    (new Thread() {
      public void run() {
        atm.withdraw(50);
      }
    }).start();    
    (new Thread() {
      public void run() {
        atm.deposit(100);
      }
    }).start();    


  } // main
} // ThreadExample
