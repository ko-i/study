use ansi_term::Color;
use ansi_term::Style;

fn main() {
    println!("This is {} in color, {} in color and {} in color",
        Color::Red.paint("red"),
        Color::Blue.paint("blue"),
        Color::Green.paint("Green"));

    println!("{} and this is not", Style::new().bold().paint("This is Bold"));

    println!("{}. {} and {}",
        Color::Yellow.paint("This is colored"),
        Style::new().bold().paint("this is bold"),
        Color::Yellow.bold().paint("this is bold and colored"));

    println!("{}", Style::new().underline().paint("This is underline"));

    println!("{}", Style::new().blink().paint("I am  blink!"));
}
