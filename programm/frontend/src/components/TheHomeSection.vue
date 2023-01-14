<template>
  <div class="_wrapper">
    <div class="_column">
      <h1>Project 'GloK'</h1>
      <div :class="{ '_btn': true, '_disabled': isSupported }" @click="requestDevice()">
        <small>Подключить Bluetooth устройтсво</small>
      </div>
      <h3>Информация об устройстве</h3>
      <small> Статус: {{ isConnected }}</small>
      <small> Устройство: {{ device }}</small>
      <small> Сервер: {{ server }}</small>
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