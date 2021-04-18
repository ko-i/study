use std::io::{self, Write};

trait WriteHtml {
    fn write_html(&mut self, html: &HtmlDocument) -> io::Result<()>;

}

impl<W: Write> WriteHtml for W {
    fn write_html(&mut self, html: &HtmlDocument) -> io::Result<()> {
        
    }
}