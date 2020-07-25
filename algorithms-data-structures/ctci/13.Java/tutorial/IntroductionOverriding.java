/**
 * A tutorial for language features in Java.
 */

import java.util.ArrayList;
import java.util.Vector;
import java.util.LinkedList;
import java.util.Iterator;
import java.util.HashMap;

abstract class Shape {
  public void printMe() {
    System.out.println("I am a shape!");
  }

  public abstract double computeArea();
}

class Circle extends Shape {
  private double radius = 5;
  
  public Circle() {
    super();  
  }

  public Circle(double radius) {
    super();
    this.radius = radius;
  }

  @Override
  public void printMe() {
    System.out.println("I am a circle!");
  }

  public double computeArea() {
    return Math.PI * this.radius * this.radius;
  }
}

class Rectangle extends Shape {
  private double length = 10;
  private double width = 5;

  public double computeArea() {
    return this.length * this.width;
  }
}

public class IntroductionOverriding {
  public static void main(String[] args) {
    
    // A dynamically resizing array
    System.out.println();
    System.out.println("ArrayList Demo");
    ArrayList<Shape> shapesArrayList = new ArrayList<Shape>();
    shapesArrayList.add(new Circle());
    shapesArrayList.add(new Rectangle());
    shapesArrayList.add(new Circle(10));
    for (Shape s : shapesArrayList) {
      s.printMe();
      System.out.println(s.computeArea());
    }

    // A dynamically resizing array (similar to array list - but synchronized).
    System.out.println();
    System.out.println("Vector Demo");
    Vector<Shape> shapesVector = new Vector<Shape>();
    shapesVector.add(new Circle(1));
    shapesVector.add(new Rectangle());
    shapesVector.add(new Circle(2));
    for (Shape s : shapesVector) {
      s.printMe();
      System.out.println(s.computeArea());
    }

    // LinkedList and the use of an iterator
    System.out.println();
    System.out.println("LinkedList Demo (With Iterator)");
    LinkedList<Shape> shapesLinkedList = new LinkedList<Shape>();
    shapesLinkedList.add(new Circle(3));
    shapesLinkedList.add(new Rectangle());
    shapesLinkedList.add(new Circle(4));
    Iterator<Shape> iter = shapesLinkedList.iterator();
    while (iter.hasNext()) {
      Shape s = iter.next();
      s.printMe();
      System.out.println(s.computeArea());
    }

    // HashMap Example
    System.out.println();
    System.out.println("HashMap Demo");
    HashMap<String, Shape> shapeNameMap = new HashMap<String, Shape>();
    shapeNameMap.put("First Circle", new Circle(8));
    shapeNameMap.put("First Rectangle", new Rectangle());
    shapeNameMap.get("First Circle").printMe();
    System.out.println(shapeNameMap.get("First Circle").computeArea());
    shapeNameMap.get("First Rectangle").printMe();
    System.out.println(shapeNameMap.get("First Rectangle").computeArea());
  }
}
