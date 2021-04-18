use std::thread::spawn;

fn process_files(filenames: Vec<String>) -> io::Result<()> {
    for document in filenames {
        let text = load(&document)?;
        let results = process(text);
        save(&document, results)?;
    }
}

fn process_files_in_parallel(filenames: Vec<String>) -> io::Result<()> {
    const NTHREADS: usize = 8;

    let worklists = split_vec_into_chunks(filenames, NTHREADS);

    // split
    let mut thread_handles = vec![];
    for worklist in worklists {
        thread_handles.push(spawn(move || process_files(worklist)));
    }

    // merge
    for handle in thread_handles {
        handle.join().unwrap()?;
    }

    Ok(())
}