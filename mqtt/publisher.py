import paho.mqtt.publish as publish

publish.single("uselesspc/test/simple", "payload", hostname="iot.eclipse.org")