use std::thread;
use std::time::Duration;

fn main() {
    let parked_thread = thread::Builder::new().spawn(|| {
        println!("Breaking thread");

        thread::park();

        println!("Thread unparked");
    }).unwrap();

    thread::sleep(Duration::from_millis(10));
    println!("unparked the thread");

    parked_thread.thread().unpark();
    parked_thread.join().unwrap();
}