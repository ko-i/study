use std::thread;
use std::sync::mpsc::channel;

fn main() {
    let (tx, rx) = channel();

    thread::spawn(move || {
        tx.send(10).unwrap();
    });

    println!("{:?}", rx.recv().unwrap());
}