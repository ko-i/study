fn main() {
    let message = "To: jimb\r\n\
                   From: id\r\n\
                   \r\n\
                   Ooooooh, donuts\r\n";

    let mut lines = message.lines();

    println!("Headers:");
    for header in lines.by_ref().take_while(|l| !l.is_empty()) {
        println!("{:?}", header);
    }

    println!("\nBody:");
    for body in lines {
        println!("{:?}", body);
    }
}