<?xml version="1.0" encoding="iso-8859-1"?> 

<!-- Written by:	Jeremy High 
	 Student ID:	103306452
	 Written on:	October 21st, 2013
	 
	 Takes course.xml and translates 
	 it into course.html using XSLT -->

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<html>
	<head>
		<title>Courses</title>
		<script>
			function addDisplay(details) {
				document.write(details);
			}
		</script>
	</head>
	<body>
		<table border="1">
			<thead>
				<tr>
					<td align="center"><b>Course No.</b></td>
					<td align="center"><b>Course Title</b></td>
					<td align="center"><b>Prof</b></td>
					<td align="center"><b>Year</b></td>
					<td align="center"><b>Days</b></td>
					<td align="center"><b>Time</b></td>
					<td align="center"><b>Location</b></td>
				</tr>
			</thead>
			<tbody>
				<xsl:for-each select="courses/course"><xsl:if test="@acad_year > 2002">
					<tr> 
						<!-- Lists course numbers in table cell -->
						<td>
							<xsl:for-each select="course_num">
								<xsl:if test="position() != last()">
									<xsl:value-of select="."/>,
								</xsl:if>
								<xsl:if test="position() = last()">
									<xsl:value-of select="."/>
								</xsl:if>
							</xsl:for-each>
						</td> 

						<!-- Opens a pop-up with the course description
							 when you click the hyperlinked course name -->
						<td><a>
							<xsl:attribute name="href">JavaScript:addDisplay('<xsl:value-of select="description"/>');</xsl:attribute>
							<xsl:value-of select="title"/> 
						</a></td>
						
						<!-- Lists professors for the course -->
						<td>
							<xsl:for-each select="course_head/person/person_name">
								<xsl:if test="position() != last()">
									<xsl:value-of select="."/>,
								</xsl:if>
								<xsl:if test="position() = last()">
									<xsl:value-of select="."/>
								</xsl:if>
							</xsl:for-each>
						</td> 
						
						<td><xsl:value-of select="@acad_year"/></td> 
						<td><xsl:value-of select="meeting/meeting_days"/></td> 
						<td><xsl:value-of select="meeting/meeting_begin"/> - <xsl:value-of select="meeting/meeting_end"/></td> 
						<td><xsl:value-of select="meeting/location"/></td> 
					</tr> 
				</xsl:if></xsl:for-each>
			</tbody>
		</table>
	</body>
</html>
</xsl:template>
</xsl:stylesheet>
