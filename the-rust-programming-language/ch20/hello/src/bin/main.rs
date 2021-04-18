use std::io::prelude::*;
use std::net::TcpStream;
use std::net::TcpListener;

use std::fs;
use std::thread;
use std::time::Duration;

use hello::ThreadPool;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:7878").unwrap();
    let pool = ThreadPool::new(4);

    for stream in listener.incoming().take(2) {
        let stream = stream.unwrap();

        // println!("{}", "*".repeat(40));
        pool.execute(|| {
            println!("A new connection.");
            handle_connection(stream);
        });
    }

    println!("Shutting donw.");
}

fn handle_connection(mut stream: TcpStream) {
    let mut buffer = [0; 1024];

    stream.read(&mut buffer).unwrap();

    let get = b"GET / HTTP/1.1\r\n";
    let sleep = b"GET /sleep HTTP/1.1\r\n";

    let (status_line, filename) = if buffer.starts_with(get) {
        ("HTTP/1.1 200 OK\r\n", "hello.html")
    } else if buffer.starts_with(sleep) {
        thread::sleep(Duration::from_secs(5));
        ("HTTP/1.1 200 OK\r\n", "hello.html")
    } else {
        ("HTTP/1.1 404 NOT FOUND\r\n", "404.html")
    };

    let contents = fs::read_to_string(filename).unwrap();
    let response = format!("{}Content_Length: {}\r\n\r\n{}", status_line, contents.len(), contents);

    stream.write(response.as_bytes()).unwrap();
    stream.flush().unwrap();
}