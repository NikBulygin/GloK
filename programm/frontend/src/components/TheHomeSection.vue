<template>
  <div class="_wrapper">
    <div class="home-column _column">
      <h1>Project 'GloK'</h1>
      <small>Поддержка API {{ isSupported }}</small>
      <div class="_btn" @click="requestDevice()">
        <small>Подключить Bluetooth устройтсво</small>
      </div>
      <h3>Информация об устройстве</h3>
      <small> Подключено: {{ isConnected }}</small>
      <small v-if="device"> Устройство: {{ device }}</small>
      <small v-if="server"> Сервер: {{ server }}</small>
    </div>
  </div>
</template>

<script setup lang="ts">
import { useBluetooth } from '@vueuse/core'

const {
  isSupported,
  isConnected,
  device,
  requestDevice,
  server,
} = useBluetooth({
  acceptAllDevices: true,
})
</script>

<style scoped lang="scss">
.home-column {
  align-items: flex-start;
  width: 100%
}
</style>