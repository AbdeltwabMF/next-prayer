FROM alpine:3.15.2 As builder

RUN apk add --update --no-cache bash make g++ python3 py3-pip
RUN pip3 install --no-cache-dir --upgrade pip requests

RUN addgroup --system --gid 1001 nextprayer
RUN adduser --system --uid 1001 nextprayer

WORKDIR /app

COPY . .

RUN chown -R nextprayer:nextprayer /app

USER nextprayer

RUN make all install clean

FROM alpine:3.15.2 As runner

RUN apk add --update --no-cache python3 bash

RUN addgroup --system --gid 1001 nextprayer
RUN adduser --system --uid 1001 nextprayer

COPY --from=builder /home/nextprayer/.local/bin/* /usr/bin/
COPY --from=builder /home/nextprayer/.local/share/next-prayer /home/nextprayer/.local/share/next-prayer
COPY --from=builder /home/nextprayer/.config/next-prayer/np_config.py /home/nextprayer/.config/next-prayer/np_config.py

USER nextprayer

CMD ["next-prayer", "--hybrid"]
