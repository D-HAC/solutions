lazy val root = (project in file("."))
libraryDependencies += "org.scala-lang" % "scala-swing" % "2.10+" % "provided"
test in assembly := {}
mainClass in (Compile, run) := Some("disemvoweler.DisemvowelerUI")
