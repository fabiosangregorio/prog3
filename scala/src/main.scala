import java.io.{File, PrintWriter}

import scala.collection.mutable.ArrayBuffer
import scala.io.Source


object Main {
  class Library(var id : Int, var books : List[Book], var signupDays : Int, var booksPerDay : Int) extends Ordered[Library]{
    var booksToSend = new ArrayBuffer[Book]()
    var numBooks = this.books.length

    def libraryScore(): Int = {
      val thisBooksScore = this.books.foldLeft(0)(_ + _.score)
      this.booksPerDay * thisBooksScore / this.signupDays
    }

    def compare(that: Library): Int = this.libraryScore - that.libraryScore
    override def toString = id.toString + " :" + "NumBooks: " + numBooks + ", SignUp: " + signupDays + ", BxD: " + booksPerDay
  }


  class Book(var id: Int, var score: Int) extends Ordered[Book]{
    def compare(that: Book): Int = this.score - that.score
  }


  def main(args : Array[String]): Unit = {
    val path : String = System.getProperty("user.dir") + "\\src\\"
    val files = List(
      "a_example.txt",
      "b_read_on.txt",
      "c_incunabula.txt",
      "d_tough_choices.txt",
      "e_so_many_books.txt",
      "f_libraries_of_the_world.txt"
    )

    files.foreach(file => {
      println("STARTING PROBLEM " + file)

      // Input manipulation
      val source = Source.fromFile(new File(path + file))
      val lines = source.getLines.toList
      source.close
      val configuration = lines(0).split("\\s").map(_.toInt)
      val scores = lines(1).split("\\s").map(_.toInt)

      val numbooks = configuration(0)
      val numlibraries = configuration(1)
      val deadline = configuration(2)

      val libraries_info = lines.drop(2)
      var libraries = ArrayBuffer[Library]()

      var i = 0
      var j = 0
      while(i < libraries_info.size - 1){
        val params = libraries_info(i).split("\\s").map(_.toInt)
        val library_books = libraries_info(i+1).split("\\s").map(x => new Book(x.toInt, scores(x.toInt)))

        libraries.addOne(new Library(
            id = j,
            books = library_books.toList,
            signupDays = params(1),
            booksPerDay = params(2)
        ))
        j += 1
        i += 2
      }

      // Libraries sorting
      println("ORDLIB -- Inizio Ordinamento Librerie")
      libraries = libraries.sorted.reverse
      println("ORDLIB -- Fine Ordinamento Librerie")

      // Books filtering per library
      println("BOOKS -- Filtering Books")
      var res_libraries = ArrayBuffer[Library]() // in ordine di sign up
      var duplicate_books = ArrayBuffer[Int]()
      var total_signup_days = 0
      for(library <- libraries) {
        if(total_signup_days < deadline) {
          total_signup_days += library.signupDays
          var max_sendable_books = (deadline - total_signup_days) * library.booksPerDay
          var booksToSend = ArrayBuffer[Book]()
          for(book <- library.books.sorted.reverse if max_sendable_books > 0){
            if (!duplicate_books.contains(book.id)) {
              duplicate_books.addOne(book.id)
              booksToSend.addOne(book)
              max_sendable_books -= 1
            }
          }
          library.booksToSend = booksToSend
          res_libraries.addOne(library)
        }
      }
      println("BOOKS -- Filtering Books DONE")

      // Output creation
      res_libraries = res_libraries.filter(_.booksToSend.nonEmpty)
      val writer = new PrintWriter(new File(path + "output\\output_" + file))
      writer.append(res_libraries.size.toString +"\n")

      for(library <- res_libraries) {
        writer.append(library.id + " " + library.booksToSend.size +"\n")
        library.booksToSend.foreach(book => writer.append(book.id + " "))
        writer.append("\n")
      }

      println("FINISHED PROBLEM " + file)

      writer.close
    })
  }
}