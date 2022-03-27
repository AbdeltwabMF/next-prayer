# First stage - build the app
FROM alpine AS builder

RUN apk add --update --no-cache bash make g++ python3 py-pip

RUN pip3 install --upgrade pip
RUN pip3 install requests

WORKDIR /app
COPY . .
RUN make clean install

# Second stage - run the app
FROM alpine AS run

RUN apk add --update --no-cache g++

RUN mkdir -p /root/.local/share/next-prayer

COPY --from=builder /root/.local/bin/* /usr/bin/
COPY --from=builder /root/.local/share/next-prayer /root/.local/share/next-prayer

CMD ["np_main", "--hybrid"]
