// Disemvoweler

package disemvoweler

import scala.swing._
import scala.swing.event._

object Disemvowel {
  def translate(sentence: String): Array[String] = {
    return Array(sentence.filter("aeiou" contains _.toLower), sentence.filter("qwrtypsdfghjklzxcvbnm" contains _.toLower))
  }
}

object DisemvowelerUI extends SimpleSwingApplication {
  /*
   * NOTE: sbt treats this like a main method, you won't be able to run this in the scala IDE
   */
  
  val searchField = new TextField { columns = 32 }
  searchField.text = "You can disemvowel anything!"
  val translateButton = new Button("Disemvowel")
  translateButton.enabled = false
  val vowels = new TextArea("Vowels go here")
  val consonants = new TextArea("Consonants go here")
  translateButton.enabled = true
  
  def top = new MainFrame {
    
    title = "Disemvowel"
    
    // Search bar
    val searchLine = new BoxPanel(Orientation.Horizontal) {
      contents += searchField
      contents += Swing.HStrut(20)
      contents += translateButton
    }
      
    // Make sure that resizing only changes the resultField:
    restrictHeight(searchLine)
    
    // Main contents
    contents = new BoxPanel(Orientation.Vertical) {
      contents += searchLine
      contents += Swing.VStrut(10)
      border = Swing.EmptyBorder(10, 10, 10, 10)
      contents += vowels
      contents += Swing.VStrut(10)
      contents += consonants
    }
  
    // Create listeners for buttons
    listenTo(translateButton)
    reactions += {
      case EditDone(`searchField`) => translateNew()
      case ButtonClicked(`translateButton`) => translateNew()
    }
    
  }
    
  private def translateNew(): Unit = {
    vowels.text = "Translating..."
    consonants.text = ""
    var out = Disemvowel.translate(searchField.text)
    vowels.text = out(0)
    consonants.text = out(1)
    
  }
  
  private def restrictHeight(s: Component) {
    s.maximumSize = new Dimension(Short.MaxValue, s.preferredSize.height)
  }

}
