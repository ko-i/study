use std::thread;
use std::sync::mpsc::channel;

fn main() {
    let (tx, rx) = channel();

    for i in 0..5 {
        let tx = tx.clone();
        thread::spawn(move|| {
            tx.send(i).unwrap();
        });
    }

    // drop
    for j in rx.iter() {
        println!("{:?}", j);
    }
}