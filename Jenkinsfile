pipeline {
  agent any
  stages {
    stage('Build') {
      agent {
        label 'gcc-arm-none-eabi'
      }
      steps {
          sh '''make'''
          archiveArtifacts artifacts: 'build/*.bin', followSymlinks: false
          archiveArtifacts artifacts: 'build/*.elf', followSymlinks: false
          fingerprint 'build/*.elf'
          fingerprint 'build/*.bin'
      }
  }
}
