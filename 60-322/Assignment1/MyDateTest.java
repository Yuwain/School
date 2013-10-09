/************************************************************************
	Written by: 	Jeremy High
	Student ID:		103306452
	Written on:		September 19th, 2013

	Test class used in conjunction with MyDate for junit testing
************************************************************************/

import static org.junit.Assert.*;

import org.junit.Test;
import junit.framework.TestCase;

public class MyDateTest extends TestCase {
	MyDate d1, d2, d3, d4, d5, d6;
	
	protected void setUp() throws Exception {
		super.setUp();
		
		d1 = new MyDate("26/05/1999");
		d2 = new MyDate("08/06/1994");
		d3 = new MyDate("15/03/2000");
		
		d4 = new MyDate("25/05/1999");
		d5 = new MyDate("25/01/2000");
		d6 = new MyDate("26/05/1999");
	}
	
	public void testConstructor() {
		MyDate d7;
		
		try {
			d7 = new MyDate("x5/12/2008");
			fail("Constructor should throw an exception");
		} catch (Exception e) {
			System.out.println("Expected exception: letter in day (1/5)");
		}
		
		try {
			d7 = new MyDate("25/1a/2008");
			fail("Constructor should throw an exception");
		} catch (Exception e) {
			System.out.println("Expected exception: letter in month (2/5)");
		}
		
		try {
			d7 = new MyDate("15/12/200h");
			fail("Constructor should throw an exception");
		} catch (Exception e) {
			System.out.println("Expected exception: letter in year (3/5)");
		}
		
		try {
			d7 = new MyDate("25/19/2008");
			fail("Constructor should throw an exception");
		} catch (Exception e) {
			System.out.println("Expected exception: month value too high (4/5)");
		}
		
		try {
			d7 = new MyDate("25/00/2008");
			fail("Constructor should throw an exception");
		} catch (Exception e) {
			System.out.println("Expected exception: month value too low (5/5)");
		}
		
		try {
			d7 = new MyDate("26/05/1993");
			
			assertEquals(d7.getDay(),    26);
			assertEquals(d7.getMonth(),   5);
			assertEquals(d7.getYear(), 1993);
			assertEquals(d7.getDate(), "26/05/1993");
		} catch (Exception e) {
			fail("Constructor should not throw an exception");
		}
	}
	
	public void testlessThan() {
		assertEquals(d4.lessThan(d1), true);
		assertEquals(d4.lessThan(d2), false);
		assertEquals(d4.lessThan(d3), true);
		
		assertEquals(d5.lessThan(d1), false);
		assertEquals(d5.lessThan(d2), false);
		assertEquals(d5.lessThan(d3), true);
		
		assertEquals(d6.lessThan(d1), false);
		assertEquals(d6.lessThan(d2), false);
		assertEquals(d6.lessThan(d3), true);
	}
	
	public void testToString() {
		assertEquals(d4.toString(), "May 25, '99");
		assertEquals(d5.toString(), "January 25, '00");
		assertEquals(d6.toString(), "May 26, '99");
	}
	
	/* Accessors */
	public void testGetDay() {
		assertEquals(d1.getDay(), 26);
		assertEquals(d2.getDay(),  8);
		assertEquals(d3.getDay(), 15);
	}
	
	public void testGetMonth() {
		assertEquals(d1.getMonth(), 5);
		assertEquals(d2.getMonth(), 6);
		assertEquals(d3.getMonth(), 3);
	}
	
	public void testGetYear() {
		assertEquals(d1.getYear(), 1999);
		assertEquals(d2.getYear(), 1994);
		assertEquals(d3.getYear(), 2000);
	}
	
	public void testGetDate() {
		assertEquals(d1.getDate(), "26/05/1999");
		assertEquals(d2.getDate(), "08/06/1994");
		assertEquals(d3.getDate(), "15/03/2000");
	}
	
	/* Mutators */
	public void testSetDay(int day) {
		d1.setDay(9);
		assertEquals(d1.getDay(), 9);
		d2.setDay(9);
		assertEquals(d2.getDay(), 9);
		d3.setDay(9);
		assertEquals(d3.getDay(), 9);
	}
	
	public void testSetMonth(int month) {
		d3.setMonth(9);
		assertEquals(d3.getMonth(), 9);
		d3.setMonth(9);
		assertEquals(d3.getMonth(), 9);
		d3.setMonth(9);
		assertEquals(d3.getMonth(), 9);
	}
	
	public void testSetYear(int year) {
		d3.setYear(9);
		assertEquals(d3.getYear(), 9);
		d3.setYear(9);
		assertEquals(d3.getYear(), 9);
		d3.setYear(9);
		assertEquals(d3.getYear(), 9);
	}
	
	public void testSetDate(String date) {
		d3.setDate("09/09/1999");
		assertEquals(d3.getDate(), "09/09/1999");
		d3.setDate("09/09/1999");
		assertEquals(d3.getDate(), "09/09/1999");
		d3.setDate("09/09/1999");
		assertEquals(d3.getDate(), "09/09/1999");
	}

}
