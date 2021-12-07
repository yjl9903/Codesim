FROM silkeh/clang

ENV RUSTUP_HOME=/usr/local/rustup \
    CARGO_HOME=/usr/local/cargo \
    PATH=/usr/local/cargo/bin:$PATH \
    RUST_VERSION=1.57.0

RUN apt update; \
    apt install -y build-essential;

RUN wget https://sh.rustup.rs --output-document init.sh; \
    chmod +x init.sh; \
    ./init.sh -y --profile minimal; \
    rm init.sh; \
    chmod -R a+w $RUSTUP_HOME $CARGO_HOME; \
    rustup --version; \
    cargo --version; \
    rustc --version;

ADD . /root/Codesim

WORKDIR /root/Codesim

RUN cargo install --path .; \
    codesim --verion;
